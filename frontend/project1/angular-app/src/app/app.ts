import { Component, signal, inject, effect } from '@angular/core';
import { MaterialDemoComponent } from './material-demo.component';
import { ThemeService } from './theme.service';

@Component({
  selector: 'app-root',
  imports: [MaterialDemoComponent],
  templateUrl: './app.html',
  styleUrl: './app.scss'
})
export class App {
  protected readonly title = signal('angular-app');
  private readonly themeService = inject(ThemeService);

  protected readonly currentTheme = this.themeService.theme;

  constructor() {
    effect(() => {
      if (this.themeService.theme()) {
        this.applyTheme();
      }
    });
  }

  private applyTheme() {
    const body = document.body;
    // Remove existing theme classes
    body.classList.remove('light-theme', 'dark-theme');
    // Add the current theme class
    body.classList.add(`${this.themeService.theme()}-theme`);
  }

  toggleTheme() {
    this.themeService.toggleTheme();
  }
}
