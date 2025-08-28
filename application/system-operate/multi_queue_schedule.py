class Process:
    def __init__(self, name, burst_time, priority):
        self.name = name
        self.burst_time = burst_time
        self.remaining_time = burst_time
        self.priority = priority
        self.wait_time = 0
        self.completed = False

class DuoLevelQueueScheduler:
    def __init__(self):
        self.high_priority_queue = []
        self.low_priority_queue = []
        self.time_quantum = 3  # Time quantum for round-robin scheduling

    def add_process(self, name, burst_time, priority):
        process = Process(name, burst_time, priority)
        if priority == 1:  # High priority
            self.high_priority_queue.append(process)
        else:  # Low priority
            self.low_priority_queue.append(process)
    
    def run(self):
        total_time = 0
        completed_processes = 0

        # Process high priority queue
        while completed_processes < len(self.high_priority_queue):
            for process in self.high_priority_queue:
                if process.remaining_time > 0:
                    time_slice = min(self.time_quantum, process.remaining_time)
                    process.remaining_time -= time_slice
                    total_time += time_slice

                    # Update wait time for all priority processes
                    for p in self.high_priority_queue:
                        if p != process and p.remaining_time > 0:
                            p.wait_time += time_slice
                    for p in self.low_priority_queue:
                        if p.remaining_time > 0:
                            p.wait_time += time_slice

                    if process.remaining_time == 0:
                        process.completed = True
                        completed_processes += 1

        # Process low priority queue
        completed_processes = 0
        while completed_processes < len(self.low_priority_queue):
            for process in self.low_priority_queue:
                if process.remaining_time > 0:
                    time_slice = min(self.time_quantum, process.remaining_time)
                    process.remaining_time -= time_slice
                    total_time += time_slice

                    if process.remaining_time == 0:
                        process.completed = True
                        completed_processes += 1

        # Print results
        print("Process\tBurst Time\tWait Time")
        for process in self.high_priority_queue + self.low_priority_queue:
            print(f"{process.name}\t{process.burst_time}\t\t{process.wait_time}")

def testDuoLevelScheduler():
    scheduler = DuoLevelQueueScheduler()
    scheduler.add_process("P1", 10, 1)  # High priority
    scheduler.add_process("P2", 5, 1)   # High priority
    scheduler.add_process("P3", 8, 2)   # Low priority
    scheduler.add_process("P4", 6, 2)   # Low priority
    scheduler.run()

'''
given:

Process	    Type	    BurstTime(ms)	Assigned Queue
P1	        System  	6	            System Processes Queue
P2	        Interactive	10	            Interactive Queue
P3	        Batch	    12	            Batch Queue
P4	        System	    4	            System Processes Queue
P5	        Interactive	8	            Interactive Queue
P6	        Batch	    6	            Batch Queue

System Processes Queue:
    Highest priority.
    Uses Round Robin (RR) scheduling with a shorter time quantum(4ms).
Interactive Processes Queue:
    Medium priority.
    Uses Round Robin (RR) scheduling with a longer time quantum(8ms).
Batch Processes Queue:
    Lowest priority.
    Uses First-Come-First-Served (FCFS) scheduling.
'''
class TripleLevelQueueScheduler:
    def __init__(self):
        self.high_priority_queue = []
        self.medi_priority_queue = []
        self.low_priority_queue = []

        self.high_time_quantum = 4  # Time quantum for round-robin scheduling
        self.medi_time_quantum = 8

    def add_process(self, name, burst_time, priority):
        process = Process(name, burst_time, priority)
        if priority == 1:  # High priority(System type)
            self.high_priority_queue.append(process)
        elif priority == 2: # Medium priority(interactive type)
            self.medi_priority_queue.append(process)
        else:
            self.low_priority_queue.append(process)

    def run(self):
        total_time = 0
        completed_processes = 0

        # Process high priority queue
        while completed_processes < len(self.high_priority_queue):
            for process in self.high_priority_queue:
                if process.remaining_time > 0:
                    time_slice = min(self.high_time_quantum, process.remaining_time)
                    process.remaining_time -= time_slice
                    total_time += time_slice

                    # Update wait time for all priority processes
                    for p in self.high_priority_queue:
                        if p != process and p.remaining_time > 0:
                            p.wait_time += time_slice
                    for p in self.medi_priority_queue:
                        if p.remaining_time > 0:
                            p.wait_time += time_slice
                    for p in self.low_priority_queue:
                        if p.remaining_time > 0:
                            p.wait_time += time_slice

                    if process.remaining_time == 0:
                        process.completed = True
                        completed_processes += 1

        # Process medium priority queue
        completed_processes = 0
        while completed_processes < len(self.medi_priority_queue):
            for process in self.medi_priority_queue:
                if process.remaining_time > 0:
                    time_slice = min(self.medi_time_quantum, process.remaining_time)
                    process.remaining_time -= time_slice
                    total_time += time_slice

                    # Update wait time for all priority processes
                    for p in self.medi_priority_queue:
                        if p != process and p.remaining_time > 0:
                            p.wait_time += time_slice
                    for p in self.low_priority_queue:
                        if p.remaining_time > 0:
                            p.wait_time += time_slice

                    if process.remaining_time == 0:
                        process.completed = True
                        completed_processes += 1

        # Process low priority queue
        completed_processes = 0
        while completed_processes < len(self.low_priority_queue):
            for process in self.low_priority_queue:
                if process.remaining_time > 0:
                    time_slice = process.remaining_time
                    process.remaining_time -= time_slice
                    total_time += time_slice

                    for p in self.low_priority_queue:
                        if p != process and p.remaining_time > 0:
                            p.wait_time += time_slice
                    process.completed = True
                    completed_processes += 1

        # Print results
        print("Process\tBurst Time\tWait Time")
        for process in self.high_priority_queue + self.medi_priority_queue + self.low_priority_queue:
            print(f"{process.name}\t{process.burst_time}\t\t{process.wait_time}")

def testTripleLevelScheduler():
    scheduler = TripleLevelQueueScheduler()
    scheduler.add_process("P1", 6, 1)  # High priority
    scheduler.add_process("P2", 10, 2) # medi priority
    scheduler.add_process("P3", 12, 3) # Low priority
    scheduler.add_process("P4", 4, 1)  # High priority
    scheduler.add_process("P5", 6, 2)  # medium priority
    scheduler.add_process("P6", 8, 3)  # Low priority
    scheduler.run()


# Example usage
if __name__ == '__main__':
    testTripleLevelScheduler()
