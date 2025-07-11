# 📚 資料結構實作集

這個 repo 收錄了由 **李奕承** 實作的多種資料結構，每個結構皆為從零開始實作，並以靜態函式庫（`.a`）形式封裝，配合統一風格的 API 設計與測試程式，適合作為教學、研究與工程基礎之用。

---

## 🧩 模組總覽

| 模組名稱 | 類型 | 功能概述 |
|----------|------|-----------|
| `AVL_tree.a` | 平衡二元搜尋樹 (AVL Tree) | 插入、刪除、查找，保證 O(log n) 時間，支援圖形輸出與自訂結構嵌入。 |
| `binary_search_tree.a` | 二元搜尋樹 (BST) | 不平衡版本，支援複製、相等比對、中序與層序走訪。 |
| `libdouble_linked_list.a` | 雙向鏈結串列 | 支援前後插入、刪除、查找、串列合併與釋放。 |
| `liblinked_list.a` | 單向鏈結串列 | 支援基本插入、刪除、尾接與查找，簡潔高效。 |
| `priority_queue.a` | 優先權佇列（Heap） | 支援 MIN/MAX 模式，採陣列實作完全二元樹，具圖形化輸出。 |

---

## ⚙️ 建置方式

每個模組皆以 `.a` 靜態函式庫方式封裝，搭配獨立標頭檔使用。可參考以下範例編譯方式：

```bash
gcc -I include -Wall -o ./bin/test test.c liblinked_list.a
```

請依結構選擇對應的 `.a` 檔與 `#include` 標頭檔（如 `llSpec.h`、`AVLSpec.h` 等）。

---

## 📦 使用說明

每個資料結構都附有獨立的使用說明文件，詳列：

- 結構定義與初始化方法
- 插入 / 查找 / 刪除 等核心操作
- 回調函數撰寫規範
- 巨集 `return_to_user_struct_pointer` 協助反推自訂結構指標
- 範例程式與終端機輸出結果

請參考各子目錄中的說明書（如 `AVL_tree/使用說明書.md`）。

---

## ✨ 設計特色

- 📌 **模組化封裝**：每一個 `.a` 檔均可獨立使用與編譯，支援單元測試與重複使用。
- 🧠 **自訂資料支援**：所有結構皆以「成員嵌入 + 巨集」方式支援任意結構。
- 🧪 **完整測試流程**：所有函式均有測試案例與終端機輸出對照。
- 📈 **圖形化輸出**：`AVL`、`BST`、`Heap` 等結構支援 ASCII 圖形顯示，利於除錯與教學。

---

## 👨‍💻 作者

**李奕承**  
- GitHub: [https://github.com/lyciih]
- 本專案為學習與研究目的所開發，歡迎交流與指教！

---

## 🪪 授權 License

本專案採用 [MIT License](./LICENSE)。你可以自由使用、修改與散佈此專案，但請保留原作者資訊。

---

## 🔗 延伸閱讀

若你希望深入瞭解各模組細節，請點擊以下各模組的說明文件：

- [`AVL_tree.a` 使用說明](./AVL_tree/README.md)
- [`binary_search_tree.a` 使用說明](./binary_search_tree/README.md)
- [`libdouble_linked_list.a` 使用說明](./double_linked_list/README.md)
- [`liblinked_list.a` 使用說明](./linked_list/README.md)
- [`priority_queue.a` 使用說明](./priority_queue/README.md)

---


