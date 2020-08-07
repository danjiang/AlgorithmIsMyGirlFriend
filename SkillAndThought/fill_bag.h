//
// Created by Dan Jiang on 2020/8/5.
//

#ifndef ALGORITHMISMYGIRLFRIEND_SKILLANDTHOUGHT_FILL_BAG_H_
#define ALGORITHMISMYGIRLFRIEND_SKILLANDTHOUGHT_FILL_BAG_H_

void FillBagBacktracking(int weights[], int size, int bag_max_weight);
void FillBagDynamic(int weights[], int size, int bag_max_weight);
void FillBagAdvanceBacktracking(int weights[], int size, int bag_max_weight, int values[]);
void FillBagAdvanceDynamic(int weights[], int size, int bag_max_weight, int values[]);

#endif //ALGORITHMISMYGIRLFRIEND_SKILLANDTHOUGHT_FILL_BAG_H_
