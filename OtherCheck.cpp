#include "GoodStock.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char* GetROESearchString()
{
    char *pStrSearch = (char*)malloc(1024);
    memset(pStrSearch, 0, 1024);

    time_t now;
    struct tm *t;
    time(&now);
    t = localtime(&now);
    short year = t->tm_year + 1900;
    //last report
    short last_report_month = 0;
    short last_report_day = 30;
    if(t->tm_mon > 9){//10月以后
        last_report_month = 10;
    }else if(t->tm_mon > 7){//8月以后
        last_report_month = 8;
    }else if(t->tm_mon > 3){//4月以后
        last_report_month = 4;
    }

    //tm_mon 0-11
    if(t->tm_mon < 4){
        //年度或者第一季度报表可能没出，查看上一年度为止的报表
        year--;
        last_report_month = 10;
    }
    short last_report_year = year;
    short last_roe_year = year - 1;
    short year_seven_ago = last_roe_year - 5;
    short year_one_ago = year - 1;

    sprintf(pStrSearch, "%d年到%d年ROE≥15%，%d年%d月%d日ROE≥3.75%，上市时间大于5年，行业，%d年营收增长率，%d年净利润增长率，%d年%d月%d日营收增长率，%d年%d月%d日净利润增长率",
            year_seven_ago, last_roe_year,
            last_report_year, last_report_month, last_report_day,
            year_one_ago, year_one_ago,
            last_report_year, last_report_month, last_report_day,
            last_report_year, last_report_month, last_report_day);
    return pStrSearch;
}

/**
 * @brief CanIGetIn
 * @param hu_sheng_300_PE
 * @param hu_sheng_300_PB
 * @param zhong_zhneg_500_PE
 * @param zhong_zhneg_500_PB
 * @return
 *      true : 沪深300或者中证500任意一个，PE小于50%并且PB小于20%的情况，符合条件
 */
bool CanIGetIn(double hu_sheng_300_PE,
               double hu_sheng_300_PB,
               double zhong_zhneg_500_PE,
               double zhong_zhneg_500_PB){
    bool isCanGetIn = false;
    if(hu_sheng_300_PE < 0.5 && hu_sheng_300_PB < 0.2){
        isCanGetIn = true;
    }

    if(zhong_zhneg_500_PE < 0.5 && zhong_zhneg_500_PB < 0.2){
        isCanGetIn = true;
    }
    return isCanGetIn;
}


/**
 * @brief IsReject
 * @param growth_rate_yin_ye_shou_ru
 * @param growth_rate_yin_ye_shou_ru_year_on_year
 * @param growth_rate_jing_li_run
 * @param growth_rate_jing_li_run_year_on_year
 * @return
 *      true: 任意一个小于等于0的时候就需要剔除
 */
bool IsReject(double growth_rate_yin_ye_shou_ru,
              double growth_rate_yin_ye_shou_ru_year_on_year,
              double growth_rate_jing_li_run,
              double growth_rate_jing_li_run_year_on_year){
    bool isReject = false;
    if(growth_rate_yin_ye_shou_ru <= 0
            || growth_rate_yin_ye_shou_ru_year_on_year <= 0
            || growth_rate_jing_li_run <= 0
            ||growth_rate_jing_li_run_year_on_year <= 0){
        isReject = true;
    }
    return isReject;
}


bool CheckIndustry(char *pIndustryName){
    if(pIndustryName == 0){
        return -1;
    }
    bool isGoodIndustry = true;
    if(strstr(pIndustryName, "那些不能动的行业")){
        isGoodIndustry = false;
    }
    return isGoodIndustry;
}
