#include <Python.h>

PyObject *mvn( PyObject *self, PyObject *args, PyObject *kwargs )
{
    int *vec[1] = {1};
    int *num = 1;
    static char *keywords[] = {"vec", "num", NULL};
 
    if (PyArg_ParseTupleAndKeywords(args, kwargs, "s", keywords, &vec, &num))
    {
        return PyUnicode_FromFormat("Result:", vec*num);
    }
    return NULL;
}

static PyMethodDef mvnlib_methods[] = 
{
    { "mvn", (PyCFunction) mvn, METH_KEYWORDS, "mvn([1,2],[2]) -- return \"[2,4]"" },
    { NULL, 0, 0, NULL }
};

static struct PyModuleDef mvnlib_module = 
{
    PyModuleDef_HEAD_INIT,
    "mvn",
    NULL,
    -1,
    mvnlib_methods
};
 
 
PyMODINIT_FUNC PyInit_example(void)
{
    return PyModule_Create(&mvnlib_module);
}