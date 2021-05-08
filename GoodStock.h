#ifndef COMMON_H
#define COMMON_H

//typedef char bool;
#define false 0
#define true 1

/**
第一步 【i问财】筛选出ROE连续7年大于等于15%的公司
第二步 剔除周期股    CheckIndustry
第三步 【i问财】剔除基本面可能转坏的股票  IsReject
第四步 【理杏仁】三大定理剔除  CheckRuls1-3
第五步 贵的剔除     还没写！！！！！！！！！！！！！！
*/

//ROE连续7年大于等于15%的公司
char* GetROESearchString();

//years 2021 2020 2019 2018
//入场时机：沪深300或者中证500任意一个，PE小于50%并且PB小于20%的情况，就可以入场
bool CanIGetIn(double hu_sheng_300_PE,
               double hu_sheng_300_PB,
               double zhong_zhneg_500_PE,
               double zhong_zhneg_500_PB);

//4个指标任意一个小于等于0的时候就需要剔除
bool IsReject(double growth_rate_yin_ye_shou_ru,
              double growth_rate_yin_ye_shou_ru_year_on_year,
              double growth_rate_jing_li_run,
              double growth_rate_jing_li_run_year_on_year);

//某些行业股票千万不能买
bool CheckIndustry(char *pIndustryName);

//false: 三年间应收账款增幅相比营业收入增幅越来越大
bool CheckRuls1(double yin_ye_shou_ru_2021,
                double yin_ye_shou_ru_2020,
                double yin_ye_shou_ru_2019,
                double yin_ye_shou_ru_2018,
                double ying_shou_zhang_kuan_2021,
                double ying_shou_zhang_kuan_2020,
                double ying_shou_zhang_kuan_2019,
                double ying_shou_zhang_kuan_2018);

//false: 三年间应收存货增幅相比营业收入增幅越来越大
bool CheckRuls2(double yin_ye_shou_ru_2021,
                double yin_ye_shou_ru_2020,
                double yin_ye_shou_ru_2019,
                double yin_ye_shou_ru_2018,
                double cun_huo_2021,
                double cun_huo_2020,
                double cun_huo_2019,
                double cun_huo_2018);

//true:流动率全部为0 或者 任意两个流动率大于1
bool CheckRuls3(double liu_dong_lv_2021,
                double liu_dong_lv_2020,
                double liu_dong_lv_2019);

#endif // COMMON_H
