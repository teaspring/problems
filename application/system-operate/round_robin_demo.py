import os, sys

def round_robin(processes: list, burst_time: list, time_quantum: int):
    n = len(processes)
    remaining_time = burst_time.copy()  # Copy of the burst time
    time = 0
    wait_time = [0] * n
    ##turn_around_time = [0] * n

    while True:
        done = True
        for i in range(n):
            if remaining_time[i] > 0:
                done = False  # There are still processes left
                if remaining_time[i] > time_quantum:
                    time += time_quantum
                    remaining_time[i] -= time_quantum
                else:
                    time += remaining_time[i] # the leftover time of this slice will not used any more, ready to context switch 
                    wait_time[i] = time - burst_time[i]  # Waiting time calculation
                    remaining_time[i] = 0

        if done:
            break

    ##for i in range(n):
    ##    turn_around_time[i] = burst_time[i] + wait_time[i]

    # Print results
    print("Process\tBurst Time\tWaiting Time")
    for i in range(n):
        print(f"{processes[i]}\t{burst_time[i]}\t\t{wait_time[i]}")

# Example usage
processes = ["P1", "P2", "P3"]
burst_time = [10, 5, 8]
time_quantum = 3
round_robin(processes, burst_time, time_quantum)
## the output is
#Process Burst Time      Waiting Time    Turnaround Time
#P1      10              13              23
#P2      5               9               14
#P3      8               14              22