#include "GoodStock.h"


/**
 * @brief ThreeRules::CheckRuls1
 * @param yin_ye_shou_ru_2021
 * @param yin_ye_shou_ru_2020
 * @param yin_ye_shou_ru_2019
 * @param yin_ye_shou_ru_2018
 * @param ying_shou_zhang_kuan_2021
 * @param ying_shou_zhang_kuan_2020
 * @param ying_shou_zhang_kuan_2019
 * @param ying_shou_zhang_kuan_2018
 * @return
 *       false: 三年间应收账款增幅相比营业收入增幅越来越大
 */
bool CheckRuls1(double yin_ye_shou_ru_2021,
                double yin_ye_shou_ru_2020,
                double yin_ye_shou_ru_2019,
                double yin_ye_shou_ru_2018,
                double ying_shou_zhang_kuan_2021,
                double ying_shou_zhang_kuan_2020,
                double ying_shou_zhang_kuan_2019,
                double ying_shou_zhang_kuan_2018){
    bool isPass = false;
    if((yin_ye_shou_ru_2021-yin_ye_shou_ru_2020)<(ying_shou_zhang_kuan_2021-ying_shou_zhang_kuan_2020)){
        if((yin_ye_shou_ru_2020-yin_ye_shou_ru_2019)<(ying_shou_zhang_kuan_2020-ying_shou_zhang_kuan_2019)){
            isPass = false;
        } else {
            isPass = true;
        }
    }else {
        if((yin_ye_shou_ru_2020-yin_ye_shou_ru_2019)<(ying_shou_zhang_kuan_2020-ying_shou_zhang_kuan_2019)){
            if((yin_ye_shou_ru_2019-yin_ye_shou_ru_2018)<(ying_shou_zhang_kuan_2019-ying_shou_zhang_kuan_2018)){
                isPass = false;
            } else {
                isPass = true;
            }
        } else {
            isPass = true;
        }
    }
}

/**
 * @brief ThreeRules::CheckRuls2
 * @param yin_ye_shou_ru_2021
 * @param yin_ye_shou_ru_2020
 * @param yin_ye_shou_ru_2019
 * @param yin_ye_shou_ru_2018
 * @param cun_huo_2021
 * @param cun_huo_2020
 * @param cun_huo_2019
 * @param cun_huo_2018
 * @return
 *      false: 三年间应收存货增幅相比营业收入增幅越来越大
 */
bool CheckRuls2(double yin_ye_shou_ru_2021,
                double yin_ye_shou_ru_2020,
                double yin_ye_shou_ru_2019,
                double yin_ye_shou_ru_2018,
                double cun_huo_2021,
                double cun_huo_2020,
                double cun_huo_2019,
                double cun_huo_2018){
    bool isPass = false;
    if((yin_ye_shou_ru_2021-yin_ye_shou_ru_2020)<(cun_huo_2021-cun_huo_2020)){
        if((yin_ye_shou_ru_2020-yin_ye_shou_ru_2019)<(cun_huo_2020-cun_huo_2019)){
            isPass = false;
        } else {
            isPass = true;
        }
    } else {
        if((yin_ye_shou_ru_2020-yin_ye_shou_ru_2019)<(cun_huo_2020-cun_huo_2019)){
            if((yin_ye_shou_ru_2019-yin_ye_shou_ru_2018)<(cun_huo_2019-cun_huo_2018)){
                isPass = false;
            } else {
                isPass = true;
            }
        } else{
            isPass = true;
        }
    }
}

/**
 * @brief ThreeRules::CheckRuls3
 * @param liu_dong_lv_2021
 * @param liu_dong_lv_2020
 * @param liu_dong_lv_2019
 * @return
 *      true:流动率全部为0 或者 任意两个流动率大于1
 */
bool CheckRuls3(double liu_dong_lv_2021,
                double liu_dong_lv_2020,
                double liu_dong_lv_2019){
    bool isPass = false;
    //全部为0通过
    if(liu_dong_lv_2021==0.0 && liu_dong_lv_2020==0.0 && liu_dong_lv_2019==0.0){
        isPass = true;
    }else{
        //任意两个大于1通过
        if((liu_dong_lv_2021>1 && liu_dong_lv_2020>1)
                ||(liu_dong_lv_2021>1 && liu_dong_lv_2019>1)
                ||(liu_dong_lv_2020>1 && liu_dong_lv_2019>1)){
            isPass = true;
        }
    }
    return isPass;
}
