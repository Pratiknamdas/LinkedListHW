class node:
    def __init__(self,data):
        self.data = data
        self.next = None
    
class SinglyLL:
    def __init__(self):
        self.head = None

    # Inserting Element at First position
    def InsertatFirst(self,data):
        new_node = node(data)
        new_node.next = self.head
        self.head = new_node

        print(new_node.data)






def main():
    sobj = SinglyLL()

    sobj.InsertatFirst(11)

if __name__ == "__main__":
    main()