#include <Python.h>

PyObject *mvn( PyObject *self, PyObject *args, PyObject *kwargs )
{
    int *vec;
    int *num;
    int n,i;
    scanf("%d", &n);
    vec = (int*)malloc(n * sizeof(int));
    for (i = 0; i<n; i++)
    {
       printf("vec[%d] = ", i);
       scanf("%d", &vec[i]);
    }
    printf("num = ");
    scanf("%d",num);
    static char *keywords[] = {"vec", "num", NULL};
 
    if (PyArg_ParseTupleAndKeywords(args, kwargs, "s", keywords, &vec, &num))
    {
        return PyUnicode_FromFormat("Result:", *vec * *num);
    }
    return NULL;
}

static PyMethodDef mvnlib_methods[] = {
    {
        "mvn", // name of fucntion in python interpreter
        mvn, // function C declaration
        METH_VARARGS, // special macros about function arguments
        "multiply vector and number" // doc for function in python interpreter
    },
    { NULL, NULL, 0, NULL }
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
