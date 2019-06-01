#ifndef _NICKNAME_ERR_H_

#pragma once

typedef enum  _nickname_err {
    NN_SUCCESS = 0,   /* 成功 */
    NN_ARRAY_LESS_THAN_INPUT_LENGTH = 1,/* randomResult array length < randomResultLength */
} NICKNAME_ERR;

#endif // _NICKNAME_ERR_H_