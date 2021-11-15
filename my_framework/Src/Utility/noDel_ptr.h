#pragma once

/// <summary>
/// �l�ɂ͎Q�Ƃ�������delete���Ă͂����Ȃ��|�C���^�N���X
/// ���̕ϐ����|�C���^�̏��L���������Ă��邱�Ƃ𖾎��I�ɕ\��
/// </summary>
template <class T>
class noDel_ptr {
public:
    noDel_ptr<T>& operator =(const noDel_ptr<T>& src) 
    {
        // �����Ŏ󂯎�����C���X�^���X�i�Q�Ɓj�̓��e�ŏ㏑������
        this->ptr = src.ptr;
        // �������g�̎Q�Ƃ�Ԃ�
        return *this;
    }

    // �ێ����Ă���|�C���^�𓧉ߓI�Ɉ�����悤�ɂ���
    T* operator->() {
        return ptr;
    }

    noDel_ptr() {};
    explicit noDel_ptr(T* ptr) {
        // new ���ꂽ�A�h���X��ێ�����
        this->ptr = ptr;
    }

    ~noDel_ptr() {}

private:
    // �O������A�N�Z�X�ł��Ȃ��`�Ń|�C���^�ϐ���錾
    T* ptr = nullptr;
};