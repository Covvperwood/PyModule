#include <Python.h>
#define N 2
PyObject *mvn( PyObject *self, PyObject *args)
{
    PyObject* list1;
    PyObject* list2;
    int i;
    double vec, num;

    int *A = (int*)malloc(N * sizeof(int));
    for (i = 0; i<N; i++)
    {
       A[i] = (int*)malloc(N * sizeof(int));
    }

    if (!PyArg_ParseTuple(args, "OO", &list1, &list2)){
        return NULL;
    }

    for (i=0; i<N; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(list1, i);
	A[i] = PyFloat_AsDouble(item1);
	}
    

    
    PyObject* item2 = PySequence_Fast_GET_ITEM(list2, 0);
    num = PyFloat_AsDouble(item2);

    for(i=0; i<N;i++){
        A[i]=A[i]*num;
        printf("%d ", A[i]);
    }
    printf("\n");
    return Py_None;

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
 
 
PyMODINIT_FUNC PyInit_mvnlib(void)
{
    return PyModule_Create(&mvnlib_module);
}
