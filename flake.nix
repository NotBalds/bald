{
	inputs = {
		nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
	};
	outputs = { nixpkgs, ... }:
	let systems = [ "x86_64-linux" "aarch64-linux" ];
	in {
		defaultPackage = builtins.listToAttrs (builtins.map (system: { name = system; value =
		let pkgs = import nixpkgs { inherit system; };
		in pkgs.stdenv.mkDerivation {
			name = "bald";
			version = "v1.0.0";
			src = ./.;
			nativeBuildInputs = with pkgs; [ gnumake gcc ];
			buildPhase = "make build";
			installPhase = "mkdir -p $out/bin && cp out $out/bin/bald";
		};}) systems );
	};
}
