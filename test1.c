#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MaxSize 100

void encryption_method1(char *str, int key);
void decryption_method1(char *str, int key);
void encryption_method2(char *str, const char *key);
void decryption_method2(char *str, const char *key);
void generate_random_key(char *key);
void vigenereEncryption(char *text, const char *key);
void vigenereDecryption(char *text, const char *key);

GtkWidget *window;
GtkWidget *key_entry;
GtkWidget *text_entry;
GtkWidget *encrypt_button;
GtkWidget *decrypt_button;
GtkWidget *result_label;
GtkWidget *cipher_selector;
GtkWidget *random_key_label;
GtkWidget *key_label;
char last_generated_key[27];

void on_cipher_changed(GtkComboBox *widget, gpointer data) {
    int cipher_choice = gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
    if (cipher_choice == 0 || cipher_choice == 1) {
        gtk_widget_set_sensitive(key_entry, TRUE);
        gtk_widget_show(key_label);
        gtk_widget_show(key_entry);
    } else {
        gtk_widget_set_sensitive(key_entry, TRUE);
        gtk_widget_show(key_label);
        gtk_widget_show(key_entry);
    }
}

void on_encrypt_button_clicked(GtkWidget *widget, gpointer data) {
    int cipher_choice = gtk_combo_box_get_active(GTK_COMBO_BOX(cipher_selector));
    const gchar *text_str = gtk_entry_get_text(GTK_ENTRY(text_entry));
    char str[MaxSize];
    strcpy(str, text_str);

    if (cipher_choice == 0) {
        const gchar *key_str = gtk_entry_get_text(GTK_ENTRY(key_entry));
        int key = atoi(key_str);

        if (key <= 0) {
            gtk_label_set_text(GTK_LABEL(result_label), "Key must be positive");
            return;
        }

        encryption_method1(str, key);
    } else if (cipher_choice == 1) {
        generate_random_key(last_generated_key);
        gtk_label_set_text(GTK_LABEL(random_key_label), last_generated_key);
        
        encryption_method2(str, last_generated_key);
        
    } else {
        const gchar *key_str = gtk_entry_get_text(GTK_ENTRY(key_entry));
        vigenereEncryption(str, key_str);
    }

    gchar *result = g_strdup_printf("Encrypted message: %s", str);
    gtk_label_set_text(GTK_LABEL(result_label), result);
    g_free(result);
}

void on_decrypt_button_clicked(GtkWidget *widget, gpointer data) {
    int cipher_choice = gtk_combo_box_get_active(GTK_COMBO_BOX(cipher_selector));
    const gchar *text_str = gtk_entry_get_text(GTK_ENTRY(text_entry));
    char str[MaxSize];
    strcpy(str, text_str);

    if (cipher_choice == 0) {
        const gchar *key_str = gtk_entry_get_text(GTK_ENTRY(key_entry));
        int key = atoi(key_str);

        if (key <= 0) {
            gtk_label_set_text(GTK_LABEL(result_label), "Key must be positive");
            return;
        }

        decryption_method1(str, key);
    } else if (cipher_choice == 1) {
        const gchar *key_str = gtk_entry_get_text(GTK_ENTRY(key_entry));
        decryption_method2(str, key_str);
    } else {
        const gchar *key_str = gtk_entry_get_text(GTK_ENTRY(key_entry));
        vigenereDecryption(str, key_str);
    }

    gchar *result = g_strdup_printf("Decrypted message: %s", str);
    gtk_label_set_text(GTK_LABEL(result_label), result);
    g_free(result);
}

void copy_key_to_clipboard(GtkWidget *widget, gpointer data) {
    const gchar *key_text = gtk_label_get_text(GTK_LABEL(random_key_label));
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
    gtk_clipboard_set_text(clipboard, key_text, -1);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Cipher GUI");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_container_add(GTK_CONTAINER(window), grid);

    cipher_selector = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cipher_selector), "Shift Cipher");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cipher_selector), "Substitution Cipher");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(cipher_selector), "Vigenère Cipher");
    gtk_grid_attach(GTK_GRID(grid), cipher_selector, 0, 0, 2, 1);
    g_signal_connect(cipher_selector, "changed", G_CALLBACK(on_cipher_changed), NULL);

    key_label = gtk_label_new("Key:");
    gtk_grid_attach(GTK_GRID(grid), key_label, 0, 1, 1, 1);

    key_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), key_entry, 1, 1, 1, 1);

    GtkWidget *text_label = gtk_label_new("Text:");
    gtk_grid_attach(GTK_GRID(grid), text_label, 0, 2, 1, 1);

    text_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), text_entry, 1, 2, 1, 1);

    encrypt_button = gtk_button_new_with_label("Encrypt");
    g_signal_connect(encrypt_button, "clicked", G_CALLBACK(on_encrypt_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), encrypt_button, 0, 3, 1, 1);

    decrypt_button = gtk_button_new_with_label("Decrypt");
    g_signal_connect(decrypt_button, "clicked", G_CALLBACK(on_decrypt_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), decrypt_button, 1, 3, 1, 1);

    random_key_label = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), random_key_label, 0, 4, 2, 1);

    GtkWidget *copy_key_button = gtk_button_new_with_label("Copy Key");
    g_signal_connect(copy_key_button, "clicked", G_CALLBACK(copy_key_to_clipboard), NULL);
    gtk_grid_attach(GTK_GRID(grid), copy_key_button, 0, 5, 2, 1);

    result_label = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 6, 2, 1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

void encryption_method1(char *str, int key) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' + key) % 26) + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' + key) % 26) + 'A';
        }
    }
}

void decryption_method1(char *str, int key) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' - key + 26) % 26) + 'a';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
}

void encryption_method2(char *str, const char *key) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            int index = str[i] - 'a';
            str[i] = key[index];
        }
    }
}

void decryption_method2(char *str, const char *key) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; j < 26; j++) {
            if (str[i] == key[j]) {
                str[i] = alphabet[j];
                break;
            }
        }
    }
}

void generate_random_key(char *key) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int used[26] = {0};
    srand(time(NULL));

    for (int i = 0; i < 26; i++) 
    {
        int randomIndex;
        do {
            randomIndex = rand() % 26;
        } while (used[randomIndex]);

        key[i] = alphabet[randomIndex];
        used[randomIndex] = 1;
    }
    key[26] = '\0';
}


void vigenereEncryption(char *text, const char *key) {
    int textLen = strlen(text); // 평문 길이
    int keyLen = strlen(key);   // 키 길이
    int keyIndex = 0; // 키의 현재 문자 인덱스

    // 2. 암호화 수행
    for (int i = 0; i < textLen; i++) {
        if (isalpha(text[i])) { // 알파벳인 경우 암호화
            char textChar = text[i]; // 평문 문자 그대로 사용
            char keyChar = tolower(key[keyIndex % keyLen]); // 키 문자 소문자로 변환

            // 암호화 계산
            int textIndex = tolower(textChar) - 'a';
            int keyIndexVal = keyChar - 'a';
            char encryptedChar = 'a' + (textIndex + keyIndexVal) % 26;

            if (isupper(textChar)) { // 대문자 처리
                text[i] = toupper(encryptedChar);
            } else { // 소문자 처리
                text[i] = encryptedChar;
            }

            keyIndex++; // 키 인덱스 증가
        } else if (isspace(text[i])) { // 공백일 경우 키 인덱스 초기화
            keyIndex = 0;
        }
        // 공백이나 다른 문자는 그대로 유지
    }
}

void vigenereDecryption(char *text, const char *key) {
    int textLen = strlen(text); // 암호문 길이
    int keyLen = strlen(key);   // 키 길이
    int keyIndex = 0; // 키의 현재 문자 인덱스

    // 2. 복호화 수행
    for (int i = 0; i < textLen; i++) {
        if (isalpha(text[i])) { // 알파벳인 경우 복호화
            char textChar = text[i]; // 암호문 문자 그대로 사용
            char keyChar = tolower(key[keyIndex % keyLen]); // 키 문자 소문자로 변환

            // 복호화 계산
            int textIndex = tolower(textChar) - 'a';
            int keyIndexVal = keyChar - 'a';
            char decryptedChar = 'a' + (textIndex - keyIndexVal + 26) % 26;

            if (isupper(textChar)) { // 대문자 처리
                text[i] = toupper(decryptedChar);
            } else { // 소문자 처리
                text[i] = decryptedChar;
            }

            keyIndex++; // 키 인덱스 증가
        } else if (isspace(text[i])) { // 공백일 경우 키 인덱스 초기화
            keyIndex = 0;
        }
        // 공백이나 다른 문자는 그대로 유지
    }
}