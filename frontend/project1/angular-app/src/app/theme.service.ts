import { Injectable, signal } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class ThemeService {
  readonly theme = signal<'light' | 'dark'>('light');

  toggleTheme() {
    this.theme.update(currentTheme => currentTheme === 'light' ? 'dark' : 'light');
  }

  getTheme() {
    return this.theme();
  }
}