#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
}

char *read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("fopen failed");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *content = malloc(size + 1);
    if (!content)
    {
        perror("malloc failed");
        fclose(file);
        return NULL;
    }

    fread(content, 1, size, file);
    content[size] = '\0';

    fclose(file);
    return content;
}

Test(main_test, test_output, .init = redirect_all_std)
{
    char *expected_output = read_file("output.txt");
    cr_assert_not_null(expected_output, "Failed to read output.txt");

    system("../1 < input.txt");
    cr_log_info("=== TRIMMED EXPECTED OUTPUT ===\n%s", expected_output);
    cr_assert_stdout_eq_str(expected_output, "Output does not match expected result!");

    free(expected_output);
}