/*
 *
 * This file is part of pyGPIO2.
 * port.c is python GPIO extension.
 *



 */

#include "Python.h"
#include "../mapping.h"


 PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};


#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "port",
    NULL,
    -1,
    module_methods
};
#endif

PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
    PyInit_port(void) {
#else
    initport(void) {
#endif
    PyObject* module = NULL;


#if PY_MAJOR_VERSION >= 3
    module = PyModule_Create(&module_def);
#else
    module = Py_InitModule("port", module_methods);
#endif


    if (module == NULL)
#if PY_MAJOR_VERSION >= 3
        return module;
#else
        return;
#endif

    int i;
    int j;
    for(i = 0; i < sizeof(gpio)/sizeof(gpio[0]); i++){
        for(j = 0; j < 40; j++){
            if(!strcmp(gpio[i].pins[j].name, "")){
                break;
            }else{
                PyModule_AddObject(module, gpio[i].pins[j].name, Py_BuildValue("i", gpio[i].pins[j].offset));
            }
        }
    }

    #if PY_MAJOR_VERSION >= 3
        return module;
    #else
        return;
    #endif
}