/****************************************************************

      class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

int length(Node *head)
{
	//Write your code here
    if(head == nullptr)
    return 0;
    if(head->next ==nullptr)
    return 1;

    int len = 0;
    Node*ptr = head;
    while(ptr != nullptr)
    {
        ptr = ptr->next;
        len++;
    }
    return len;
}
