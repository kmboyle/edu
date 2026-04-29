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

  styleUrls: ['./typography-selector.component.scss'],
})
export class TypographySelectorComponent {
  // inject() enables tree-shaking and avoids empty constructor boilerplate
  private readonly dialogRef = inject(MatDialogRef);
  private readonly data = inject<TypographySelectorData>(MAT_DIALOG_DATA);

  readonly typographies = [
    { label: 'Roboto (default)', value: '"Roboto", "Helvetica", "Arial", sans-serif' },
    { label: 'Inter', value: '"Inter", "Helvetica", "Arial", sans-serif' },
    { label: 'Open Sans', value: '"Open Sans", "Helvetica", "Arial", sans-serif' },
    { label: 'Poppins', value: '"Poppins", "Helvetica", "Arial", sans-serif' },
    { label: 'Lato', value: '"Lato", "Helvetica", "Arial", sans-serif' },
    { label: 'Nunito', value: '"Nunito", "Helvetica", "Arial", sans-serif' },
    { label: 'Montserrat', value: '"Montserrat", "Helvetica", "Arial", sans-serif' },
    { label: 'Merriweather (serif)', value: '"Merriweather", "Georgia", serif' },
    { label: 'Source Code Pro (mono)', value: '"Source Code Pro", "Courier New", monospace' },
  ] as const;

  selectedTypography = signal<string>(
    this.data?.typography?.fontFamily ?? this.typographies[0].value
  );

  apply(): void {
    const fontFamily = this.selectedTypography();
    this.dialogRef.close({ fontFamily });
  }
}
