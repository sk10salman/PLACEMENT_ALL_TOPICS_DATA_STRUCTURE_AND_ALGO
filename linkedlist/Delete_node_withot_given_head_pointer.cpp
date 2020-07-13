void deleteNode(Node *node)
{
   // Your code here
   struct Node* temp = node->next; 
  
        // Copy data of the next node to current node 
        node->data = node->next->data; 
  
        // Perform conventional deletion 
        node->next = node->next->next; 
  
        free(temp); 
   
}
