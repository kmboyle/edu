# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Commands

All commands run from `angular-app/`:

```bash
pnpm start          # dev server at http://localhost:4200
pnpm run build      # production build
pnpm test           # run unit tests via Karma
```

If pnpm peer dependency conflicts arise, use `pnpm install --strict-peer-dependencies=false`.

## Architecture

This is an **Angular 21 standalone-component app** with Angular Material (M3). There is no backend.

**Theme system** — `ThemeService` (`theme.service.ts`) holds a `signal<'light' | 'dark'>`. The root `App` component watches that signal via `effect()` and toggles `.light-theme` / `.dark-theme` on `<body>`. The two M3 themes are defined once in `styles.scss` using `mat.define-theme()` and applied with `mat.all-component-themes()`.

**Component structure** — `App` is the shell; it renders `MaterialDemoComponent` which contains the sidenav, toolbar, and demo widgets. There are no routes yet (`app.routes.ts` is empty).

**Typography dialog** — `TypographySelectorService` wraps `MatDialog.open()` and returns an `Observable`. `MaterialDemoComponent` calls the service; the dialog component (`dialogs/typography-selector.component.ts`) uses `inject()` for `MatDialogRef` and `MAT_DIALOG_DATA`.

**Signals pattern** — prefer Angular `signal` / `computed` / `effect` over RxJS for local state; use RxJS only at service boundaries (e.g., `MatDialog.afterClosed()`).
