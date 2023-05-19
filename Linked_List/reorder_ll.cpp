Node<int> *rearrangeList(Node<int> *head)
{
    Node<int> *tmp = head;
    vector<int> ans;
    while (tmp)
    {
        int x = tmp->data;
        if (x != -1)
            ans.push_back(x);
        tmp = tmp->next;
    }
    tmp = head;
    int n = ans.size();
    int i = 0, j = n - 1;
    while (tmp)
    {
        tmp->data = ans[i];
        if (tmp->next)
            tmp->next->data = ans[j];
        i++;
        j--;
        if (tmp->next)
            tmp = tmp->next->next;
        else
            break;
    }
    return head;
}