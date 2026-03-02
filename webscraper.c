#include <stdio.h>
#include <curl/curl.h>

int main(void) {
    CURL *curl;     //Defines a CURL type pointer to be used as a handle in the future
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);  //Initializes libcurl resources

    curl = curl_easy_init();    //Initializes the handle to the transfers
    if (!curl) {
        fprintf(stderr, "Erro ao iniciar curl\n");
        return 1;
    }

    //Sets up the handle's options
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); //Enforce a long int

    res = curl_easy_perform(curl);  //Performs the easy transfer

    if (res != CURLE_OK) {
        fprintf(stderr, "Erro: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl); //Closes handle
    curl_global_cleanup();  //Cleans libcurl resources from memory
}