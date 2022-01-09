Node* reverse(Node* head, int k) {
    if (head == NULL or head->next == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;

    int i=0;
    while (i < k and curr != NULL) {
        curr->next = prev;

        prev = curr;
        curr = next;

        if (next != NULL) {
            next = next->next;
        }
    }

    head->next = reverse(next);
    return prev;
}

9 2 4 3 5 1

for (int i=0; i<5; i++) {
    if (arr[i] > arr[i+1]) return false;
}

return true;

target = 8
pos = 4
set = {9, 2, 4, 3}


SELECT * FROM EMPLOYEE
INNER JOIN DEPARTMENT
ON EMPLOYEE.deptid = DEPARTMENT.deptid;