#include <curl/curl.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <string>

// COEIROINK API テストコード
int main(int argc, char *argv[])
{
	std::cout << "適当に入力してね" << std::endl;
	// 入力したい文字
	std::string input_text;
	std::cin >> input_text;
	std::string output_url =
		"http://localhost:50031/audio_query\?speaker=0&text=" + input_text;
	// CURLのハンドル
	CURL *hnd;
	hnd = curl_easy_init();
	curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
	curl_easy_setopt(hnd, CURLOPT_URL, output_url.c_str());
	curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
	curl_easy_setopt(hnd, CURLOPT_HTTP_VERSION, (long)CURL_HTTP_VERSION_2TLS);
	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(hnd, CURLOPT_FTP_SKIP_PASV_IP, 1L);
	curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
	// 中間ファイルとしてとりあえず外部に出力する
	FILE *fp = fopen("out.txt", "wb");
	// 中間ファイルへ出力する
	curl_easy_setopt(hnd, CURLOPT_WRITEDATA, fp);
	// curlの実行
	curl_easy_perform(hnd);
	// ファイルの解放
	fclose(fp);
	// windowsの仕様?で日本語は直接postできないらしい...
	system(
		"curl -s -H  \"Content-Type: application/json\"  -X POST -d "
		"@out.txt "
		"\"localhost:50031/synthesis?speaker=0\" -o out.wav");

	// curlの解放
	curl_easy_cleanup(hnd);
	hnd = NULL;
	return 0;
}