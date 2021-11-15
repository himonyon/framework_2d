#pragma once

/// <summary>
/// 値には参照したいがdeleteしてはいけないポインタクラス
/// 他の変数がポインタの所有権を持っていることを明示的に表す
/// </summary>
template <class T>
class noDel_ptr {
public:
    noDel_ptr<T>& operator =(const noDel_ptr<T>& src) 
    {
        // 引数で受け取ったインスタンス（参照）の内容で上書きする
        this->ptr = src.ptr;
        // 自分自身の参照を返す
        return *this;
    }

    // 保持しているポインタを透過的に扱えるようにする
    T* operator->() {
        return ptr;
    }

    noDel_ptr() {};
    explicit noDel_ptr(T* ptr) {
        // new されたアドレスを保持する
        this->ptr = ptr;
    }

    ~noDel_ptr() {}

private:
    // 外部からアクセスできない形でポインタ変数を宣言
    T* ptr = nullptr;
};