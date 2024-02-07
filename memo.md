https://qiita.com/travelist/items/746406b5c2b8c71d718c
AOJ CLIの使い方

https://www.sambaiz.net/article/320/
C++で標準入力から数が不定なスペース区切りの文字列を読み込んで分割する
getlineを使う方法

以下、istringstreamを使う方法
according to chatgpt
https://chat.openai.com/share/31fcaaaf-5c93-40e7-af3f-1a547fb34eb5
```cpp
int main() {
  string input;
  // エンドラインまでの入力を読み取る
  getline(std::cin, input);

  // std::istringstreamを使って空白区切りの文字列をcinから読み取る
  istringstream iss(input);
  string        word;
  while (iss >> word) {
    // 読み取った入力を処理する（ここでは単純に出力する）
    cout << "入力: " << word << endl;
  }

  return 0;
}
```

https://code.visualstudio.com/docs/cpp/config-linux
