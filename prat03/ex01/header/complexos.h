typedef struct complexo numComplexo;

numComplexo* cria_nro(float a, float b);

void libera_nro(numComplexo *i);

numComplexo* soma(numComplexo *i1, numComplexo *i2);

numComplexo* sub(numComplexo *i1, numComplexo *i2);

numComplexo* mult(numComplexo *i1, numComplexo *i2);

void mostrarComplexo(numComplexo *i);