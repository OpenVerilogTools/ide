{
  description = "OpenVerilogTools IDE";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      supportedSystems = [ "x86_64-linux" "aarch64-linux" "aarch64-darwin" ];
      
      forAllSystems = f: nixpkgs.lib.genAttrs supportedSystems (system: f system);
    in {
      devShells = forAllSystems (system:
        let
          pkgs = import nixpkgs { inherit system; };
        in
        {
          default = pkgs.mkShell {
            nativeBuildInputs = with pkgs; [
              # Build toolchain 
              cmake
              ninja
              qt6.wrapQtAppsHook
            ];

            buildInputs = with pkgs; [
              # Compiler & debugger
              clang
              lldb
              ccache

              # Dev tools
              clang-tools
              cppcheck
              git
              
              # Qt6 
              qt6.qtbase
              qt6.qtdeclarative
              
              # Libraries
              eigen
            ];

            shellHook = ''
              # Unset Homebrew Qt variables
              unset QMAKE QMAKEMODULES QMAKEPATH QT_PLUGIN_PATH
              
              export CMAKE_PREFIX_PATH="${pkgs.qt6.qtbase}/lib/cmake:${pkgs.eigen}/lib/cmake"
              export Qt6_DIR="${pkgs.qt6.qtbase}/lib/cmake/Qt6"

              # export PATH="${pkgs.qt6.qtbase}/bin:$PATH"
  
              echo "--- Qt6 Nix Environment Active ---"
              echo "CMAKE_PREFIX_PATH: $CMAKE_PREFIX_PATH"
              echo "Qt6_DIR: $Qt6_DIR"
              echo "Run 'cmake -B build -G Ninja' to configure."
            '';
          };
        });
    };
}
