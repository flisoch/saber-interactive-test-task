#include "List.h"
#include <vector>

/*
    Алгоритм сериализации структуры, которая является графом с циклами описан тут:
    https://isocpp.org/wiki/faq/serialization#serialize-with-cycles
*/

void List::Serialize(FILE *file)
{
    std::map<ListNode *, int> ids;
    SaveToMap(head, ids);

    for (auto &[key, value] : ids)
    {
        int nextId = key->next == NULL ? -1 : ids[key->next];
        int prevId = key->prev == NULL ? -1 : ids[key->prev];
        int randId = key->rand == NULL ? -1 : ids[key->rand];

        fprintf(file, "%d %s %d %d %d\n", value, key->data.c_str(), nextId, prevId, randId);
    }
    fflush(file);
}

void List::Deserialize(FILE *file)
{
    // парсить файл сишными функциями сложно/долго
}

void List::Deserialize(std::ifstream &file)
{
    std::vector<ListNode *> nodes;

    int curId, nextId, prevId, randId;
    std::string data;

    while (file >> curId >> data >> nextId >> prevId >> randId)
    {
        ListNode *newNode = new ListNode();
        newNode->data = data;
        nodes.insert(nodes.begin() + curId, newNode);
    }

    file.clear();
    file.seekg(0, file.beg);

    while (file >> curId >> data >> nextId >> prevId >> randId)
    {
        ListNode *curNode = nodes[curId];
        curNode->next = nextId == -1 ? NULL : nodes[nextId];
        curNode->prev = prevId == -1 ? NULL : nodes[prevId];
        curNode->rand = randId == -1 ? NULL : nodes[randId];
        Insert(curNode);
    }
}

void List::SaveToMap(ListNode *currentNode, std::map<ListNode *, int> &ids)
{
    if (currentNode == NULL) // отсутствующие ноды не добавляем
    {
        return;
    }
    else
    {
        if (ids.find(currentNode) == ids.end()) // если ещё не добавили
        {
            unsigned int id = ids.size(); //уникальный id для ноды
            ids.insert(std::pair<ListNode *, int>(currentNode, id));
        }
        else // второй раз не добавляем
        {
            return;
        }
    }

    // рекурсивно добавляем все ноды, которые относятся к текущей ноде
    SaveToMap(currentNode->prev, ids);
    SaveToMap(currentNode->next, ids);
    SaveToMap(currentNode->rand, ids);
}

void List::Insert(ListNode *node)
{

    if (head == NULL)
    {
        head = node;
        tail = head;
    }
    else
    {
        if (tail == head)
        {
            tail = node;
            head->next = tail;
            tail->prev = head;
        }

        else
        {
            ListNode *tempNode = tail;
            node->prev = tempNode;
            tempNode->next = node;
            tail = node;
        }
    }

    count++;
}
