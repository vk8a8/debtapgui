# Maintainer: vk8a8 <vk8a8@protonmail.com>
pkgname=debtapgui
pkgver=1.1
pkgrel=1
pkgdesc="QT Frontend for Debtap"
arch=('x86_64')
url='https://github.com/vk8a8/debtapgui'
license=(GPL-3.0-or-later)
depends=('bash' 'qt5-base' 'gcc-libs' 'glibc')
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

    install -Dm755 debtapgui "$pkgdir/usr/bin/debtapgui"

    install -Dm644 ../mainwindow.h "$pkgdir/usr/include/debtapgui/mainwindow.h"

    install -Dm755 "$srcdir/debtapgui.sh" "$pkgdir/usr/share/debtapgui/debtapgui.sh"
}

md5sums=('f028fcb576aa66a794a4fd22845980af'
         'b98ec590a8f41807893387d9a3486ea4'
         '46d5fa8f4492f6448e90453c5377b045'
         '9a24fa22f2d2ce6b8a0bb9d56c0e3237'
         'bde82db62fc74340307089a562a9d753'
         '55b7db2627829fabfd733c317b740d32')
