import { Component, OnInit } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { ThemePalette } from '@angular/material/core';

@Component({
  selector: 'app-typography-selector',
  templateUrl: './typography-selector.component.html',
  styleUrls: ['./typography-selector.component.scss'],
  imports: [FormsModule]
})
export class TypographySelectorComponent {
  selectedTypography: string = 'default';
  typographies: string[] = ['default', 'sans-serif', 'serif', 'monospace'];

  constructor() { }
  updateTypography() {
    // Logic to apply selected typography
    const theme = this.matTheme;
    (theme.typography as any).fontFamily = this.selectedTypography;
  }

  get matTheme() {
    return { typography: {} };
  }
}