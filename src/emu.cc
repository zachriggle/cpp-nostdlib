#include <stdlib.h>
#include <unistd.h>  /* for write(), also available on Windows */
extern "C" void* emulate_cc_new(unsigned len) { \
  void *p = malloc(len);
  if (p == 0) {
    /* Don't use stdio (e.g. fputs), because that may want to allocate more
     * memory.
     */
    (void)!write(2, "out of memory\n", 14);
    abort();
  }
  return p;
}
extern "C" void emulate_cc_delete(void* p) {
  if (p != 0)
    free(p);
}
void* operator new  (size_t len)   __attribute__((alias("emulate_cc_new")));
void* operator new[](size_t len  ) __attribute__((alias("emulate_cc_new")));   
void  operator delete  (void* p)   __attribute__((alias("emulate_cc_delete")));
void  operator delete[](void* p)   __attribute__((alias("emulate_cc_delete")));
void* __cxa_pure_virtual = 0;
void* __gxx_personality_v0 = 0;

namespace __cxxabiv1 {
    class __class_type_info {
        virtual void dummy();
    };
    void __class_type_info::dummy() { }  // causes the vtable to get created here
    class __si_class_type_info {
	virtual void dummy();
    };
    void __si_class_type_info::dummy() { }
};
