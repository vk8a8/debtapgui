# Maintainer: vk8a8 <vk8a8@protonmail.com>
pkgname=debtapgui
pkgver=1.1
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
         'aac768f583299e46c6c7e81106866b1c'
         '46d5fa8f4492f6448e90453c5377b045'
         '9a24fa22f2d2ce6b8a0bb9d56c0e3237'
         '4257ff35c27c4d9f65a0eb38c0afc6d3'
         '55b7db2627829fabfd733c317b740d32')
