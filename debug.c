/*
 *  debug.c
 *  KeychainToken
 *
 *  Created by Jay Kline on 7/1/09.
 *  Copyright 2009 All rights reserved.
 *
 */


#include "debug.h"


char *hexify(unsigned char *data, int len) {
    char *s;
    int i;
    char hexDigits[] = { '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    
    s = (char *)malloc(len * 2 + 1);
    if (!s) return(NULL);
    memset(s, 0, len * 2 + 1);
    
    for  (i=0; i<len; i++) {
        s[i*2] = hexDigits[(data[i] >> 4) & 0x0f];
        s[i*2 + 1] = hexDigits[data[i] & 0x0f];
    }
    return(s);
}

char *stringify(unsigned char *str, int length) {
    static char my_string[128];
    
    if (length >= 128) return(NULL);
    memset(my_string, 0, sizeof(my_string));
    memcpy(my_string, str, length);
    my_string[length] = 0;
    return(my_string);
}


const char * getCKRName(CK_RV rv) {
    switch (rv) {
        case CKR_OK: return "CKR_OK";
        case CKR_CANCEL: return "CKR_CANCEL";
        case CKR_HOST_MEMORY: return "CKR_HOST_MEMORY";
        case CKR_SLOT_ID_INVALID: return "CKR_SLOT_ID_INVALID";
        case CKR_GENERAL_ERROR: return "CKR_GENERAL_ERROR";
        case CKR_FUNCTION_FAILED: return "CKR_FUNCTION_FAILED";
        case CKR_ARGUMENTS_BAD: return "CKR_ARGUMENTS_BAD";
        case CKR_NO_EVENT: return "CKR_NO_EVENT";
        case CKR_NEED_TO_CREATE_THREADS: return "CKR_NEED_TO_CREATE_THREADS";
        case CKR_CANT_LOCK: return "CKR_CANT_LOCK";
        case CKR_ATTRIBUTE_READ_ONLY: return "CKR_ATTRIBUTE_READ_ONLY";
        case CKR_ATTRIBUTE_SENSITIVE: return "CKR_ATTRIBUTE_SENSITIVE";
        case CKR_ATTRIBUTE_TYPE_INVALID: return "CKR_ATTRIBUTE_TYPE_INVALID";
        case CKR_ATTRIBUTE_VALUE_INVALID: return "CKR_ATTRIBUTE_VALUE_INVALID";
        case CKR_DATA_INVALID: return "CKR_DATA_INVALID";
        case CKR_DATA_LEN_RANGE: return "CKR_DATA_LEN_RANGE";
        case CKR_DEVICE_ERROR: return "CKR_DEVICE_ERROR";
        case CKR_DEVICE_MEMORY: return "CKR_DEVICE_MEMORY";
        case CKR_DEVICE_REMOVED: return "CKR_DEVICE_REMOVED";
        case CKR_ENCRYPTED_DATA_INVALID: return "CKR_ENCRYPTED_DATA_INVALID";
        case CKR_ENCRYPTED_DATA_LEN_RANGE: return "CKR_ENCRYPTED_DATA_LEN_RANGE";
        case CKR_FUNCTION_CANCELED: return "CKR_FUNCTION_CANCELED";
        case CKR_FUNCTION_NOT_PARALLEL: return "CKR_FUNCTION_NOT_PARALLEL";
        case CKR_FUNCTION_NOT_SUPPORTED: return "CKR_FUNCTION_NOT_SUPPORTED";
        case CKR_KEY_HANDLE_INVALID: return "CKR_KEY_HANDLE_INVALID";
        case CKR_KEY_SIZE_RANGE: return "CKR_KEY_SIZE_RANGE";
        case CKR_KEY_TYPE_INCONSISTENT: return "CKR_KEY_TYPE_INCONSISTENT";
        case CKR_KEY_NOT_NEEDED: return "CKR_KEY_NOT_NEEDED";
        case CKR_KEY_CHANGED: return "CKR_KEY_CHANGED";
        case CKR_KEY_NEEDED: return "CKR_KEY_NEEDED";
        case CKR_KEY_INDIGESTIBLE: return "CKR_KEY_INDIGESTIBLE";
        case CKR_KEY_FUNCTION_NOT_PERMITTED: return "CKR_KEY_FUNCTION_NOT_PERMITTED";
        case CKR_KEY_NOT_WRAPPABLE: return "CKR_KEY_NOT_WRAPPABLE";
        case CKR_KEY_UNEXTRACTABLE: return "CKR_KEY_UNEXTRACTABLE";
        case CKR_MECHANISM_INVALID: return "CKR_MECHANISM_INVALID";
        case CKR_MECHANISM_PARAM_INVALID: return "CKR_MECHANISM_PARAM_INVALID";
        case CKR_OBJECT_HANDLE_INVALID: return "CKR_OBJECT_HANDLE_INVALID";
        case CKR_OPERATION_ACTIVE: return "CKR_OPERATION_ACTIVE";
        case CKR_OPERATION_NOT_INITIALIZED: return "CKR_OPERATION_NOT_INITIALIZED";
        case CKR_PIN_INCORRECT: return "CKR_PIN_INCORRECT";
        case CKR_PIN_INVALID: return "CKR_PIN_INVALID";
        case CKR_PIN_LEN_RANGE: return "CKR_PIN_LEN_RANGE";
        case CKR_PIN_EXPIRED: return "CKR_PIN_EXPIRED";
        case CKR_PIN_LOCKED: return "CKR_PIN_LOCKED";
        case CKR_SESSION_CLOSED: return "CKR_SESSION_CLOSED";
        case CKR_SESSION_COUNT: return "CKR_SESSION_COUNT";
        case CKR_SESSION_HANDLE_INVALID: return "CKR_SESSION_HANDLE_INVALID";
        case CKR_SESSION_PARALLEL_NOT_SUPPORTED: return "CKR_SESSION_PARALLEL_NOT_SUPPORTED";
        case CKR_SESSION_READ_ONLY: return "CKR_SESSION_READ_ONLY";
        case CKR_SESSION_EXISTS: return "CKR_SESSION_EXISTS";
        case CKR_SESSION_READ_ONLY_EXISTS: return "CKR_SESSION_READ_ONLY_EXISTS";
        case CKR_SESSION_READ_WRITE_SO_EXISTS: return "CKR_SESSION_READ_WRITE_SO_EXISTS";
        case CKR_SIGNATURE_INVALID: return "CKR_SIGNATURE_INVALID";
        case CKR_SIGNATURE_LEN_RANGE: return "CKR_SIGNATURE_LEN_RANGE";
        case CKR_TEMPLATE_INCOMPLETE: return "CKR_TEMPLATE_INCOMPLETE";
        case CKR_TEMPLATE_INCONSISTENT: return "CKR_TEMPLATE_INCONSISTENT";
        case CKR_TOKEN_NOT_PRESENT: return "CKR_TOKEN_NOT_PRESENT";
        case CKR_TOKEN_NOT_RECOGNIZED: return "CKR_TOKEN_NOT_RECOGNIZED";
        case CKR_TOKEN_WRITE_PROTECTED: return "CKR_TOKEN_WRITE_PROTECTED";
        case CKR_UNWRAPPING_KEY_HANDLE_INVALID: return "CKR_UNWRAPPING_KEY_HANDLE_INVALID";
        case CKR_UNWRAPPING_KEY_SIZE_RANGE: return "CKR_UNWRAPPING_KEY_SIZE_RANGE";
        case CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT: return "CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT";
        case CKR_USER_ALREADY_LOGGED_IN: return "CKR_USER_ALREADY_LOGGED_IN";
        case CKR_USER_NOT_LOGGED_IN: return "CKR_USER_NOT_LOGGED_IN";
        case CKR_USER_PIN_NOT_INITIALIZED: return "CKR_USER_PIN_NOT_INITIALIZED";
        case CKR_USER_TYPE_INVALID: return "CKR_USER_TYPE_INVALID";
        case CKR_USER_ANOTHER_ALREADY_LOGGED_IN: return "CKR_USER_ANOTHER_ALREADY_LOGGED_IN";
        case CKR_USER_TOO_MANY_TYPES: return "CKR_USER_TOO_MANY_TYPES";
        case CKR_WRAPPED_KEY_INVALID: return "CKR_WRAPPED_KEY_INVALID";
        case CKR_WRAPPED_KEY_LEN_RANGE: return "CKR_WRAPPED_KEY_LEN_RANGE";
        case CKR_WRAPPING_KEY_HANDLE_INVALID: return "CKR_WRAPPING_KEY_HANDLE_INVALID";
        case CKR_WRAPPING_KEY_SIZE_RANGE: return "CKR_WRAPPING_KEY_SIZE_RANGE";
        case CKR_WRAPPING_KEY_TYPE_INCONSISTENT: return "CKR_WRAPPING_KEY_TYPE_INCONSISTENT";
        case CKR_RANDOM_SEED_NOT_SUPPORTED: return "CKR_RANDOM_SEED_NOT_SUPPORTED";
        case CKR_RANDOM_NO_RNG: return "CKR_RANDOM_NO_RNG";
        case CKR_DOMAIN_PARAMS_INVALID: return "CKR_DOMAIN_PARAMS_INVALID";
        case CKR_BUFFER_TOO_SMALL: return "CKR_BUFFER_TOO_SMALL";
        case CKR_SAVED_STATE_INVALID: return "CKR_SAVED_STATE_INVALID";
        case CKR_INFORMATION_SENSITIVE: return "CKR_INFORMATION_SENSITIVE";
        case CKR_STATE_UNSAVEABLE: return "CKR_STATE_UNSAVEABLE";
        case CKR_CRYPTOKI_NOT_INITIALIZED: return "CKR_CRYPTOKI_NOT_INITIALIZED";
        case CKR_CRYPTOKI_ALREADY_INITIALIZED: return "CKR_CRYPTOKI_ALREADY_INITIALIZED";
        case CKR_MUTEX_BAD: return "CKR_MUTEX_BAD";
        case CKR_MUTEX_NOT_LOCKED: return "CKR_MUTEX_NOT_LOCKED";
        case CKR_NEW_PIN_MODE: return "CKR_NEW_PIN_MODE";
        case CKR_NEXT_OTP: return "CKR_NEXT_OTP";
        case CKR_FUNCTION_REJECTED: return "CKR_FUNCTION_REJECTED";
        case CKR_VENDOR_DEFINED: return "CKR_VENDOR_DEFINED";
        default:
            return "";
    }
}


void
debug(int level, const char *format, ...) {
#ifdef DEBUG 
    va_list args;
    
    if (level > DEBUG_LEVEL)
        return;
    
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
#else
    /* empty */
#endif
}