#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct {
    double n;
    lept_type type;
}lept_value;

enum {
    LEPT_PARSE_OK = 0,  //检验成功，是合法的
    LEPT_PARSE_EXPECT_VALUE,   //若一个JSON只含有空白
    LEPT_PARSE_INVALID_VALUE,   //若值不是那三种字面值
    LEPT_PARSE_ROOT_NOT_SINGULAR   //若一个值之后，在空白之后还有其他字符			  
};

int lept_parse(lept_value* v, const char* json);

lept_type lept_get_type(const lept_value* v);

double lept_get_number(const lept_value* v);

#endif /* LEPTJSON_H__ */
