# labpilot releases

Download and run labpilot on Ubuntu lab computers or M2 Mac.

---

## Ubuntu Intel/Ryzen

```bash
curl -L -o labpilot https://raw.githubusercontent.com/YOUR_USERNAME/YOUR_REPO/main/labpilot-linux-amd64
chmod +x labpilot
./labpilot
```

Password: `ProjectA13A23`

---

## M2 Mac

```bash
curl -L -o labpilot-macos-arm64 https://raw.githubusercontent.com/YOUR_USERNAME/YOUR_REPO/main/labpilot-macos-arm64
chmod +x labpilot-macos-arm64
xattr -d com.apple.quarantine ./labpilot-macos-arm64 2>/dev/null || true
./labpilot-macos-arm64
```

Password: `ProjectA13A23`

---

## Install System-Wide On Ubuntu

```bash
curl -L -o labpilot https://raw.githubusercontent.com/YOUR_USERNAME/YOUR_REPO/main/labpilot-linux-amd64
chmod +x labpilot
sudo mv labpilot /usr/local/bin/labpilot
labpilot
```

---

## Host Setup

Run on the machine where you will run labpilot.

```bash
sudo apt update
sudo apt install -y nmap openssh-client curl
```

---

## Target Setup

Run on machines you want to control over SSH.

```bash
sudo apt update
sudo apt install -y openssh-server curl libnotify-bin
sudo systemctl enable --now ssh
```

Target SSH login:
- username: `cse`
- password: `cse`

---

## Files

| File | Use on |
|------|--------|
| labpilot-linux-amd64 | Ubuntu Intel/Ryzen computers |
| labpilot-macos-arm64 | Apple Silicon Mac (M1/M2/M3/M4) |

---

## Notes

- Replace `YOUR_USERNAME/YOUR_REPO` in URLs after creating your GitHub repo.
- Ubuntu college PCs with Intel or Ryzen CPUs should use `labpilot-linux-amd64`.
- Keep this README in the root of your public `dist` repo so download links work.
