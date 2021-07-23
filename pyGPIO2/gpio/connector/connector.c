/*
 *
 * This file is part of pyGPIO2.
 * connector.c is python GPIO extension.
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
    "connector",
    NULL,
    -1,
    module_methods
};
#endif

PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
    PyInit_connector(void) {
#else
    initconnector(void) {
#endif
    PyObject* module = NULL;


#if PY_MAJOR_VERSION >= 3
    module = PyModule_Create(&module_def);
#else
    module = Py_InitModule("connector", module_methods);
#endif


    if (module == NULL)
#if PY_MAJOR_VERSION >= 3
        return module;
#else
        return;
#endif

    int i;
    int j;
    char name[20];
    for(i = 0; i < sizeof(gpio)/sizeof(gpio[0]); i++){
        for(j = 0; j < 40; j++){
            if(!strcmp(gpio[i].pins[j].name, "")){
                break;
            }else{
                sprintf(name, "%sp%d", gpio[i].connector_name, gpio[i].pins[j].pin_number);
                PyModule_AddObject(module, name, Py_BuildValue("i", gpio[i].pins[j].offset));
            }
        }
    }

    #if PY_MAJOR_VERSION >= 3
        return module;
    #else
        return;
    #endif
}