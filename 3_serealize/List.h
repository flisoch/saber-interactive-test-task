
#include <string>
#include <stdio.h>
#include <fstream>
#include <map>

struct ListNode
{
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *rand = NULL; // указатель на произвольный элемент данного

    std::string data;
};

class List
{
public:

    void Serialize(FILE *file);
    void Deserialize(FILE *file);
    void Deserialize(std::ifstream& file);
    void Insert(ListNode* node);

private:
    void SaveToMap(ListNode *currentNode, std::map<ListNode *, int> &ids);

    ListNode *head = NULL;
    ListNode *tail = NULL;
    int count = 0;
};
