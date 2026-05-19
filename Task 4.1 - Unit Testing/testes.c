#include "./senha.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

void testar_senha(void)
{
    char classe[20];
    int ret;

    /* Teste 1: Length 0 - 3 → "Fraca" */
    /*  Boundary testing
        We test the boundaries of the length categories to ensure correct classification, especially at the edges where the classification changes.
    */
    ret = classificar_senha(0, classe);
    if (ret == 1 && strcmp(classe, "Fraca") == 0)
        printf("Test 1 passed\n");
    else
        printf("Test 1 failed\n");

    ret = classificar_senha(3, classe);
    if (ret == 1 && strcmp(classe, "Fraca") == 0)
        printf("Test 1 passed\n");
    else
        printf("Test 1 failed\n");

    /* Teste 2: Length 4 - 7    → "Media" */
    ret = classificar_senha(4, classe);
    if (ret == 1 && strcmp(classe, "Media") == 0)
        printf("Test 2 passed   \n");
    else
        printf("Test 2 failed\n");

    ret = classificar_senha(7, classe);
    if (ret == 1 && strcmp(classe, "Media") == 0)
        printf("Test 2 passed   \n");
    else
        printf("Test 2 failed\n");

    /* Teste 3: Length 8 - 15   → "Forte" */
    ret = classificar_senha(8, classe);
    if (ret == 1 && strcmp(classe, "Forte") == 0)
        printf("Test 3 passed\n");
    else
        printf("Test 3 failed\n");

    ret = classificar_senha(15, classe);
    if (ret == 1 && strcmp(classe, "Forte") == 0)
        printf("Test 3 passed\n");
    else
        printf("Test 3 failed\n");

    /* Teste 4: Length 16 - 30 → "Muito Forte" */
    classe[0] = '\0';
    ret = classificar_senha(16, classe);
    if (ret == 1 && strcmp(classe, "Muito Forte") == 0)
        printf("Test 4 passed\n");
    else
        printf("Test 4 failed\n");

    classe[0] = '\0';
    ret = classificar_senha(31, classe);
    if (ret == 1 && strcmp(classe, "Muito Forte") == 0)
        printf("Test 4 passed\n");
    else
        printf("Test 4 failed\n");

    /* Teste 5: Length -1 → retorno 0 */
    ret = classificar_senha(-1, classe); // returning true even when length is negative is a bug, as it should return false (0) in this case
    if (ret == 0)
        printf("Test 5 passed\n");
    else
        printf("Test 5 failed\n");

    /* Teste 6: classe NULL → return 0 */
    ret = classificar_senha(5, NULL);
    if (ret == 0)
        printf("Test 6 passed\n");
    else
        printf("Test 6 failed\n");
}

void testar_senha_assert(void)
{

    int ret;
    char classe[20];

    /* Teste 1: Length 0 - 3 → "Fraca" */
    ret = classificar_senha(0, classe);
    assert(ret == 1 && strcmp(classe, "Fraca") == 0);
    ret = classificar_senha(3, classe);
    assert(ret == 1 && strcmp(classe, "Fraca") == 0);
    /* Teste 2: Length 4 - 7    → "Media" */
    ret = classificar_senha(4, classe);
    assert(ret == 1 && strcmp(classe, "Media") == 0);
    ret = classificar_senha(7, classe);
    assert(ret == 1 && strcmp(classe, "Media") == 0);
    /* Teste 3: Length 8 - 15   → "Forte" */
    ret = classificar_senha(8, classe);
    assert(ret == 1 && strcmp(classe, "Forte") == 0);
    ret = classificar_senha(15, classe);
    assert(ret == 1 && strcmp(classe, "Forte") == 0);
    /* Teste 4: Length 16 - 30 → "Muito Forte" */
    classe[0] = '\0';
    ret = classificar_senha(16, classe);
    assert(ret == 1 && strcmp(classe, "Muito Forte") == 0);
    classe[0] = '\0';
    ret = classificar_senha(31, classe);
    assert(ret == 1 && strcmp(classe, "Muito Forte") == 0);
    /* Teste 5: Length -1 → retorno 0 */
    ret = classificar_senha(-1, classe);
    assert(ret == 0);
    /* Teste 6: classe NULL → return 0 */
    ret = classificar_senha(5, NULL);
    assert(ret == 0);
}

int main(void)
{
    // testar_senha();
    testar_senha_assert();
    return 0;
}