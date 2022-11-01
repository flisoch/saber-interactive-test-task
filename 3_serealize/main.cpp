
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

#include "List.h"

const std::string FILE_PATH = "./serialize.bin";

int main() {

    List l1;
    ListNode* n1 = new ListNode();
    n1->data = "AA";
    ListNode* n2 = new ListNode();
    n2->data = "BB";
    ListNode* n3 = new ListNode();
    n3->data = "CC";

    n1->rand = n3;
    n3->rand = n1;

    l1.Insert(n1);
    l1.Insert(n2);
    l1.Insert(n3);


    FILE* fp;
    fp = fopen(FILE_PATH.c_str(), "wb");
    l1.Serialize(fp);
    fclose(fp);


    List l2;
    std::ifstream ifs(FILE_PATH.c_str());
    l2.Deserialize(ifs);    // в дебаггере можно убедиться, что списки l1 и l2 совпадают
    ifs.close();

}