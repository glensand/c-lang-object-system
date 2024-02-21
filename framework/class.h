/* Copyright (C) 2021 - 2024 Gleb Bezborodov - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the MIT license.
 *
 * You should have received a copy of the MIT license with
 * this file. If not, please write to: bezborodoff.gleb@gmail.com,
 * or visit : https://github.com/glensand/c-lang-object-system
 */

#pragma once

#include <stddef.h>
#include <stdarg.h>

typedef void (*vtable_method)(void *this, ...);

typedef struct vtable_t {
    size_t size;
    vtable_method* methods;
} vtable_t;

typedef struct class_t {
    void *(*ctor)(void *this, va_list *args);
    void *(*dtor)(void *this);

    vtable_t vtable;
    size_t object_size;
} class_t;

void *new(const void *type, ...);
void delete(void *item);

#define call_method(this, method_index, ...) \
    {                                         \
        const class_t **macro_cp = this; \
        assert(macro_cp); \
        const class_t* macro_class_casted = *cp; \
        assert(macro_class_casted->vtable.size > method_index); \
        const vtable_method macro_method = macro_class_casted->vtable.methods[method_index]; \
        (*macro_method)(this, __VA_ARGS__); \
    } \
