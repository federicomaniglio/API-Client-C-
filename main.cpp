#include <iostream>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

// Funzione callback per scrivere la risposta dalla richiesta HTTP
size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

int main() {
    CURL *curl;
    CURLcode res;
    std::string apiKey = "50bd8bca8aacd051cbfab3b538308aa8";
    std::string city = "Vicenza"; // Cambia con la città desiderata
    std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);

        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Failed to perform HTTP request: " << curl_easy_strerror(res) << std::endl;
        } else {
            nlohmann::json jsonResponse = nlohmann::json::parse(response);
            double temperature = jsonResponse["main"]["temp"];  // Extracting temperature from JSON

            // Convert the temperature from Kelvin to Celsius
            temperature -= 273.15;

            std::cout << "Temperature in Celsius:" << std::endl;
            std::cout << temperature << std::endl;
        }

        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Failed to initialize cURL." << std::endl;
    }

    return 0;
}