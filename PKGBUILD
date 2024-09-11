# Maintainer: vk8a8 <vk8a8@protonmail.com>
pkgname=debtapgui
pkgver=1.0
pkgrel=1
pkgdesc="QT Frontend for Debtap"
arch=('any')
depends=('bash' 'qt6-base' 'debtap')
makedepends=('cmake' 'qt6-tools')
source=("main.cpp" "mainwindow.cpp" "mainwindow.h" "CMakeLists.txt" "debtapgui.sh" "mainwindow.ui")
md5sums=('SKIP' 'SKIP' 'SKIP' 'SKIP')

build() {
    mkdir -p build
    cd build
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr
    cmake --build .
}

package() {
    cd build

    install -Dm755 debtapgui "$pkgdir/usr/local/bin/debtapgui"

    install -Dm644 ../mainwindow.h "$pkgdir/usr/local/include/debtapgui/mainwindow.h"

    install -Dm755 "$srcdir/debtapgui.sh" "$pkgdir/usr/share/debtapgui/debtapgui.sh"
}

md5sums=('f028fcb576aa66a794a4fd22845980af'
         'bf4599307e51c9304217bffed8a86dc2'
         '46d5fa8f4492f6448e90453c5377b045'
         '9a24fa22f2d2ce6b8a0bb9d56c0e3237'
         '0e9ccd5b4f2d539eb2e1562f787b61fb'
         '989ff0a3c35419c100ad4ad03a072cca')
