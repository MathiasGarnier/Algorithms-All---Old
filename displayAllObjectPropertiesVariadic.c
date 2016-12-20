char* displayAllObjectProperties(int count, ...) {

  va_list args;
  int i;
  char returnedValue[512];

  va_start(args, count);
  for (i = 0; i < count; i++) {

    struct Object *o = va_arg(args, struct Object*);

    return o->identifier;
  }
  va_end(args);
}
