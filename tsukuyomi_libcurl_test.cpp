#include <curl/curl.h>
#include <stdio.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

// COEIROINK API テストコード
int main(int argc, char *argv[])
{
	// CURLのハンドル
	CURL *hnds;

	// curlの初期化
	hnds = curl_easy_init();
	// バッファの設定
	curl_easy_setopt(hnds, CURLOPT_BUFFERSIZE, 102400L);
	// COEIROINKのURL
	curl_easy_setopt(hnds, CURLOPT_URL,
					 "localhost:50031/audio_query\?speaker=0&text=m");
	// COEIROINKにpostする内容
	curl_easy_setopt(hnds, CURLOPT_POSTFIELDS,
					 "localhost:50031/audio_query\?speaker=0&text=m");
	curl_easy_setopt(hnds, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)53);
	curl_easy_setopt(hnds, CURLOPT_MAXREDIRS, 50L);

	curl_easy_setopt(hnds, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(hnds, CURLOPT_FTP_SKIP_PASV_IP, 1L);
	curl_easy_setopt(hnds, CURLOPT_TCP_KEEPALIVE, 1L);
	// 中間ファイルとしてとりあえず外部に出力する
	char  outfilename[FILENAME_MAX] = "out.txt";
	FILE *fp;
	fp = fopen(outfilename, "wb");
	// 中間ファイルへ出力する
	curl_easy_setopt(hnds, CURLOPT_WRITEDATA, fp);
	// ファイルの解放
	fclose(fp);
	// curlの実行
	curl_easy_perform(hnds);
	// curlの解放
	curl_easy_cleanup(hnds);
	hnds = NULL;
	// なぜか中間ファイルを読み込めないからとりあえず別ファイルとして作成したやつを読み込む
	FILE		 *fpg = NULL;
	std::string	  moji;
	std::ifstream ifs("outs.txt");
	// string型なので一行だとこれで読み込める
	getline(ifs, moji);
	// CURLのハンドルを新たに作る
	CURL *hnd;
	// コンテンツタイプの指定
	struct curl_slist *slist1;
	slist1 = NULL;
	slist1 = curl_slist_append(slist1, "Content-Type: application/json");

	hnd = curl_easy_init();
	curl_easy_setopt(hnd, CURLOPT_BUFFERSIZE, 102400L);
	// synthesisは音声を合成する箇所
	curl_easy_setopt(hnd, CURLOPT_URL, "localhost:50031/synthesis\?speaker=0");
	curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
	curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, moji.c_str());
	curl_easy_setopt(hnd, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)468);
	curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, slist1);
	curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.83.1");
	curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
	curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
	curl_easy_setopt(hnd, CURLOPT_FTP_SKIP_PASV_IP, 1L);
	curl_easy_setopt(hnd, CURLOPT_TCP_KEEPALIVE, 1L);
	// 生成したファイルをダウンロードする
	char  outfilenames[FILENAME_MAX] = "out.wav";
	FILE *fps;
	fps = fopen(outfilenames, "wb");
	curl_easy_setopt(hnd, CURLOPT_WRITEDATA, fps);
	curl_easy_perform(hnd);

	curl_easy_cleanup(hnd);
	hnd = NULL;
	curl_slist_free_all(slist1);
	slist1 = NULL;

	return 0;
}
