import { Component, inject } from '@angular/core';
import { MatButtonModule } from '@angular/material/button';
import { MatCardModule } from '@angular/material/card';
import { MatFormFieldModule } from '@angular/material/form-field';
import { MatInputModule } from '@angular/material/input';
import { MatSliderModule } from '@angular/material/slider';
import { MatToolbarModule } from '@angular/material/toolbar';
import { MatIconModule } from '@angular/material/icon';
import { MatDialogModule, MatDialog } from '@angular/material/dialog';
import { FormsModule } from '@angular/forms';
import { TypographySelectorService } from './services/typography-selector.service';
import { MatSidenavModule } from '@angular/material/sidenav';

@Component({
  selector: 'app-material-demo',
  templateUrl: './material-demo.component.html',
  styleUrls: ['./material-demo.component.scss'],
  standalone: true,
  imports: [
    MatButtonModule,
    MatCardModule,
    MatFormFieldModule,
    MatInputModule,
    MatSliderModule,
    MatToolbarModule,
    MatIconModule,
    MatDialogModule,
    FormsModule,
    MatSidenavModule
  ]
})
export class MaterialDemoComponent {
  sliderValue = 50;
  inputValue = '';
  title = 'Material Components Demo';

  private readonly typographySelectorService = inject(TypographySelectorService);
  private readonly dialog = inject(MatDialog);

  openTypographyDialog(): void {
    this.typographySelectorService.openTypographySelector().subscribe(result => {
      if (result) {
        console.log('Selected font family:', result.fontFamily);
      }
    });
  }
}