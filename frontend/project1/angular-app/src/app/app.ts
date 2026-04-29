import { Component, signal, inject, effect } from '@angular/core';
import { MaterialDemoComponent } from './material-demo.component';
import { ThemeService } from './theme.service';
import { TypographySelectorService } from './services/typography-selector.service';

@Component({
  selector: 'app-root',
  imports: [MaterialDemoComponent],
  templateUrl: './app.html',
  styleUrl: './app.scss'
})
export class App {
  protected readonly title = signal('angular-app');
  private readonly themeService = inject(ThemeService);
  private readonly typographySelectorService = inject(TypographySelectorService);

  protected readonly currentTheme = this.themeService.theme;

  constructor() {
    // Apply theme when component initializes
    this.applyTheme();

    // Watch for theme changes and re-apply theme
    effect(() => {
      // This effect will run whenever the theme signal changes
      this.applyTheme();
    });

    effect(() => {
      document.body.style.fontFamily = this.typographySelectorService.fontFamily();
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
