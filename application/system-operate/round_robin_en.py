class Process:
    def __init__(self, name, burst_time):
        self.name = name
        self.burst_time = burst_time
        self.remaining_time = burst_time
        self.wait_time = 0
        self.completed = False

class Scheduler:
    def __init__(self):
        self.processes = []
        self.time_quantum = 5  # Initial time quantum
        self.queue = []
    
    def add_process(self, name, burst_time):
        process = Process(name, burst_time)
        self.processes.append(process)
        self.queue.append(process)
    
    def adjust_time_quantum(self, average_wait_time):
        if average_wait_time > 4:  # Example threshold
            self.time_quantum = max(1, self.time_quantum - 1)  # Decrease time quantum
        elif average_wait_time < 2:
            self.time_quantum += 1  # Increase time quantum

    def run(self):
        total_time = 0
        completed_processes = 0

        while completed_processes < len(self.processes):
            # sort by order of remaining_time, like Shortest Job Next
            self.queue.sort(key=lambda x: x.remaining_time)

            total_wait_time = 0
            for process in self.queue:
                if process.remaining_time > 0:
                    time_slice = min(self.time_quantum, process.remaining_time)
                    process.remaining_time -= time_slice
                    total_time += time_slice

                    # Update wait time for other processes
                    for p in self.queue:
                        if p != process and p.remaining_time > 0:
                            p.wait_time += time_slice
                    
                    if process.remaining_time == 0:
                        process.completed = True
                        completed_processes += 1

                total_wait_time += process.wait_time
            
            average_wait_time = total_wait_time / len(self.queue) if completed_processes < len(self.processes) else 0
            self.adjust_time_quantum(average_wait_time)

        # Print results
        print("Process\tBurst Time\tWait Time")
        for process in self.processes:
            print(f"{process.name}\t{process.burst_time}\t\t{process.wait_time}")

# Example usage
scheduler = Scheduler()
scheduler.add_process("P1", 10)
scheduler.add_process("P2", 5)
scheduler.add_process("P3", 8)
scheduler.run()