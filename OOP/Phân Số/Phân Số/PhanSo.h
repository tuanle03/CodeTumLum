//
//  PhanSo.h
//  PhanSo
//
//  Created by Tuấn Lê on 24/03/2022.
//

#ifndef PhanSo_h
#define PhanSo_h

class PhanSo {
    int tuso;
    int mauso;

public:
    PhanSo();
    PhanSo(int tuso, int mauso);
//        ~PhanSo();

    void getPhanSo();
    void outPhanSo();
    PhanSo Cong(PhanSo b);
    PhanSo Tru(PhanSo b);
    PhanSo Nhan(PhanSo b);
    PhanSo Chia(PhanSo b);
};

#endif /* PhanSo_h */

