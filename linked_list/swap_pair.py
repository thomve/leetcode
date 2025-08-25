class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def swap(head: ListNode) -> ListNode:
    dummy = ListNode(0)   # Dummy node to handle edge cases
    dummy.next = head
    prev = dummy
    
    while head and head.next:
        # Nodes to swap
        first = head
        second = head.next
        
        # Swapping
        prev.next = second
        first.next = second.next
        second.next = first
        
        # Move pointers forward
        prev = first
        head = first.next
    
    return dummy.next
