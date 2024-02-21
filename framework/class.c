#include "class.h"
#include "assert.h"
#include "stdlib.h"

void *new(const void *type, ...) {
    const class_t *class_casted = type;
    void *p = malloc(class_casted->object_size);
    assert(p);

    // each object have to has pointer to ints class at the very beginning of definition
    *(const class_t **)p = class_casted;

    if (class_casted->ctor) {
        va_list ap;
        va_start(ap, type);
        p = class_casted->ctor(p, &ap);
        va_end(ap);
    }

    return p;
}

void delete(void *this) {
    const class_t **cp = this;

    if (this && *cp && (*cp)->dtor)
        this = (*cp)->dtor(this);

    free(this);
}
