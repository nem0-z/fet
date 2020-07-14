class todo:
    __slots__ = 'id_', 'title_', 'desc_', 'prior_'

    def __init__(self, ID, TITLE, DESC, PRIOR):
        self.id_ = ID
        self.title_ = TITLE
        self.desc_ = DESC
        self.prior_ = PRIOR

    def print(self):
        print("Task id:", self.id_)
        print("Task title:", self.title_)
        print("Task description:", self.desc_)
        print("Task priority:", self.prior_)


def solution():
    def createtask():
        print("Input task id, title, description and priority separated by comma.")
        data = [x.strip() for x in input().split(',')]
        if len(data) not in range(5):
            raise ValueError
        task = todo(data[0], data[1], data[2], data[3])
        return task

    def printmenu():
        print("1.New task\n2.Show all tasks\n3.Mark task as done\n4.Exit")
        choice = int(input())
        return choice

    def addtask(toadd):
        tasklist.append(toadd)
        tasklist.sort(key=lambda toadd:toadd.prior_)

    tasklist = []

    while True:
        choice = printmenu()
        if choice == 1:
            try:
                newtask = createtask()
            except Exception:
                print("Bad input")
                continue
            if newtask not in tasklist:
                addtask(newtask)
            else:
                print("Existing task is already in list.")
        elif choice == 2:
            for task in tasklist:
                task.print()
        elif choice == 3:
            taskid = input("Task (id) you want to remove: ")
            toremove = [task for task in tasklist if task.id_ == taskid]
            for task in toremove:
                tasklist.remove(task)
        elif choice == 4:
            break
        else:
            print("Bad input")

solution()


