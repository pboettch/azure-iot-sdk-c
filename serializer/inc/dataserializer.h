// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#ifndef DATASERIALIZER_H
#define DATASERIALIZER_H

#include "macro_utils.h"
#include "multitree.h"
#include "buffer_.h"

#ifdef __cplusplus
#include <cstddef>
extern "C"
{
#else
#include <stddef.h>
#endif

/*Codes_SRS_DATA_SERIALIZER_07_001: [DataSerializer will have the following interface]*/
#define DATA_SERIALIZER_RESULT_VALUES           \
DATA_SERIALIZER_INVALID_ARG,                    \
DATA_SERIALIZER_ERROR							\

DEFINE_ENUM(DATA_SERIALIZER_RESULT, DATA_SERIALIZER_RESULT_VALUES);

#define DATA_SERIALIZER_MULTITREE_TYPE_VALUES   \
    DATA_SERIALIZER_TYPE_CHAR_PTR,              \
    DATA_SERIALIZER_TYPE_AGENT_DATA             \

DEFINE_ENUM(DATA_SERIALIZER_MULTITREE_TYPE, DATA_SERIALIZER_MULTITREE_TYPE_VALUES);

typedef BUFFER_HANDLE (*DATA_SERIALIZER_ENCODE_FUNC)(MULTITREE_HANDLE multiTreeHandle, DATA_SERIALIZER_MULTITREE_TYPE dataType);
typedef MULTITREE_HANDLE (*DATA_SERIALIZER_DECODE_FUNC)(BUFFER_HANDLE decodeData);

extern BUFFER_HANDLE DataSerializer_Encode(MULTITREE_HANDLE multiTreeHandle, DATA_SERIALIZER_MULTITREE_TYPE dataType, DATA_SERIALIZER_ENCODE_FUNC encodeFunc);
extern MULTITREE_HANDLE DataSerializer_Decode(BUFFER_HANDLE data, DATA_SERIALIZER_DECODE_FUNC decodeFunc);

#ifdef __cplusplus
}
#endif

#endif // DATASERIALIZER_H
