#include "Python.h"

// print function.

static PyObject*
print(PyObject *self, PyObject *args)
{
  const char *str;

  if (!PyArg_ParseTuple(args, "s:print", &str)) {
    return NULL;
  }

  printf("%s\n", str);

  return Py_BuildValue("s", NULL);
}

// add function.

static PyObject*
add(PyObject *self, PyObject *args)
{
  long a, b;
  PyObject *pA, *pB;

  if (!PyArg_ParseTuple(args, "ll:add", &a, &b)) {
    return NULL;
  }

  pA = PyLong_FromLong(a);
  pB = PyLong_FromLong(b);

  PyObject *r = PyNumber_Add(pA, pB);

  Py_DECREF(pA);
  Py_DECREF(pB);

  return r;
}

// Module functions table.

static PyMethodDef
module_functions[] = {
  { "print", print, METH_VARARGS, "Print something." },
  { "add", add, METH_VARARGS, "Add two numbers." },
  { NULL }
};

// This function is called to initialize the module.

static struct PyModuleDef example =
{
  PyModuleDef_HEAD_INIT,
  "example",
  "A minimal module.",
  -1,
  module_functions
};

PyMODINIT_FUNC PyInit_example(void)
{
  return PyModule_Create(&example);
}
