import { Component, inject, signal } from '@angular/core';
import { MAT_DIALOG_DATA, MatDialogRef } from '@angular/material/dialog';
import { MatFormFieldModule } from '@angular/material/form-field';
import { MatSelectModule } from '@angular/material/select';
import { MatButtonModule } from '@angular/material/button';

// @angular/material/theming was removed in v15+. Theming is now CSS-based.
// Define a lightweight local interface for the typography payload.
interface TypographyConfig {
  fontFamily: string;
}

interface TypographySelectorData {
  typography?: TypographyConfig;
}

@Component({
  selector: 'app-typography-selector',
  standalone: true,
  imports: [MatFormFieldModule, MatSelectModule, MatButtonModule],
  templateUrl: './typography-selector.component.html',
  styleUrl: './typography-selector.component.scss',
})
export class TypographySelectorComponent {
  // inject() enables tree-shaking and avoids empty constructor boilerplate
  private readonly dialogRef = inject(MatDialogRef<TypographySelectorComponent>);
  private readonly data = inject<TypographySelectorData>(MAT_DIALOG_DATA);

  // Predefined, well-known font families — safe by definition (no user-supplied CSS injection)
  readonly typographies = [
    { label: 'Default', value: '"Roboto", "Helvetica", "Arial", sans-serif' },
    { label: 'Sans-Serif', value: '"Helvetica Neue", Helvetica, Arial, sans-serif' },
    { label: 'Serif', value: '"Georgia", "Times New Roman", serif' },
    { label: 'Monospace', value: '"Courier New", Courier, monospace' },
  ] as const;

  selectedTypography = signal<string>(
    this.data.typography?.fontFamily ?? this.typographies[0].value
  );

  apply(): void {
    const fontFamily = this.selectedTypography();
    this.dialogRef.close({ fontFamily });
  }
}
